#include <complex>
#include <valarray>

const double PI = 3.1415192653589793238460;


typedef std::complex<double> ComplexVal; //short-hand for complex<double> representing a+bi
typedef std::valarray<ComplexVal> SampleArray; //array of complex-valued samples

class CooleyTukeyFFT
{
public:
	CooleyTukeyFFT();
	CooleyTukeyFFT(std::string const& _filePath, int const& _slicingSize);

	void FFT(SampleArray &values); //in-place fft
	void iFFT(SampleArray &fft); //in-place inverse fft
	std::string* getPathOfSource();
	int getFFTSize();

private:
	std::string path;
	int FFTSize;
};
