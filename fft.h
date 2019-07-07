#ifndef __OHMBASS_FFT__
#define __OHMBASS_FFT__
#pragma once
#include <complex>

#include <iostream>
#include <valarray>

#include <Winbase.h>
#include "../WDL/fft.c"

const float nPI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
int cont = 0;



// Cooley–Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
//void fft(CArray& x)
//{
//	const size_t N = x.size();
//	if (N <= 1) return;
//
//	// divide
//	CArray even = x[std::slice(0, N / 2, 2)];
//	CArray  odd = x[std::slice(1, N / 2, 2)];
//
//	// conquer
//	fft(even);
//	fft(odd);
//
//	// combine
//	for (size_t k = 0; k < N / 2; ++k)
//	{
//		Complex t = std::polar(1.0, -2 * nPI * k / N) * odd[k];
//		x[k] = even[k] + t;
//		x[k + N / 2] = even[k] - t;
//	}
//}

// Cooley-Tukey FFT (in-place, breadth-first, decimation-in-frequency)
// Better optimized but less intuitive
// !!! Warning : in some cases this code make result different from not optimased version above (need to fix bug)
// The bug is now fixed @2017/05/30 
void fft(CArray &x)
{
	//Log
	char buf[52];
	cont = cont + 1;
	sprintf(buf, "Contador: %d \n", cont);
	OutputDebugString(buf);


	// DFT
	unsigned int N = x.size(), k = N, n;
	double thetaT = 3.14159265358979323846264338328L / N;
	Complex phiT = Complex(cos(thetaT), -sin(thetaT)), T;
	while (k > 1)
	{
		n = k;
		k >>= 1;
		phiT = phiT * phiT;
		T = 1.0L;
		for (unsigned int l = 0; l < k; l++)
		{
			for (unsigned int a = l; a < N; a += n)
			{
				unsigned int b = a + k;
				Complex t = x[a] - x[b];
				x[a] += x[b];
				x[b] = t * T;
			}
			T *= phiT;
		}
	}
	// Decimate
	unsigned int m = (unsigned int)log2(N);
	for (unsigned int a = 0; a < N; a++)
	{
		unsigned int b = a;
		// Reverse bits
		b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
		b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
		b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
		b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
		b = ((b >> 16) | (b << 16)) >> (32 - m);
		if (b > a)
		{
			Complex t = x[a];
			x[a] = x[b];
			x[b] = t;
		}
	}
	//// Normalize (This section make it not working correctly)
	//Complex f = 1.0 / sqrt(N);
	//for (unsigned int i = 0; i < N; i++)
	//	x[i] *= f;
}

// inverse fft (in-place)
void ifft(CArray& x)
{
	// conjugate the complex numbers
	x = x.apply(std::conj);

	// forward fft
	fft(x);

	// conjugate the complex numbers again
	x = x.apply(std::conj);

	// scale the numbers
	x /= x.size();
}

int test_fft() {
	const Complex test[] = { 1.0, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0, -1.0 };
	CArray data(test, 8);

	//Log
	char buf[52];

	//Real
	for (int i = 0; i < 8; ++i)
	{
		sprintf(buf, "Valor Real %d: %f \n", i, data[i]);
		OutputDebugString(buf);
	}

	// forward fft
	fft(data);
	for (int i = 0; i < 8; ++i)
	{
		sprintf(buf, "Valor FFT %d[0]: %f \n", i, data[i]._Val[0]);
		OutputDebugString(buf);
		sprintf(buf, "Valor FFT %d[1]: %f \n", i, data[i]._Val[1]);
		OutputDebugString(buf);
	}

	// inverse fft
	ifft(data);
	for (int i = 0; i < 8; ++i)
	{
		sprintf(buf, "Valor Invertido %d: %f \n", i, data[i]);
		OutputDebugString(buf);
	}
	return 0;
}

void test2()
{
	//Log
	char buff[52];
	WDL_fft_init();

	static const int LEN = 16;
	WDL_FFT_COMPLEX buf[LEN];

	//for (int i = 0; i < LEN; ++i)
	//{
	//	// Test signal: Naive square wave
	//	buf[i].re = i < LEN / 2 ? 1.0 : -1.0;
	//	buf[i].im = 0.0;
	//	sprintf(buff, "%f\t%f\n", buf[i].re, buf[i].im);
	//	OutputDebugString(buff);
	//}
	//sprintf(buff, "\n");
	//OutputDebugString(buff);

	WDL_fft(buf, LEN, 0);
	for (int i = 0; i < LEN; ++i)
	{
		int sorted_idx = WDL_fft_permute(LEN, i);
		WDL_FFT_REAL re = buf[sorted_idx].re, im = buf[sorted_idx].im;
		sprintf(buff, "%f\t%f\n", re, im);

		// \todo Convert complex data to something meaningful, e.g. amplitude and phase.
		 double amp = sqrt(re*re + im*im);
		 double phase = -atan2(im, re);
		 sprintf(buff, "Amp: %f\t Phase: %f\n", amp, phase);
		 OutputDebugString(buff);
	}
	sprintf(buff, "\n");
	OutputDebugString(buff);

	/*WDL_fft(buf, LEN, 1);
	for (int i = 0; i < LEN; ++i)
	{
		const double scale = (double)1 / LEN;
		sprintf(buff, "%f\t%f\n", buf[i].re * scale, buf[i].im * scale);
		OutputDebugString(buff);
	}
	sprintf(buff, "\n");
	OutputDebugString(buff);*/
}

#endif
