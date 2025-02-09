#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "FFT.h"

class Spectrogram
{
public:
	Spectrogram(CooleyTukeyFFT fft);


	void generateSignalWindow();
	void spectrum(float const& maxSpectrumBars);
	void scrollingSpectrum(float const& maxSpectrumDistance);
	void scrollingHorizontalSpectrum(float const& maxSpectrumDistance);
	void ToggleDisp();
	void update();
	void draw(sf::RenderWindow &window);

private:
	
	CooleyTukeyFFT fft;
	sf::SoundBuffer buf;
	sf::Sound sounds;

	int sampleRate;
	int sampleCount;
	int FFTSize;
	int currSample;


	char doubleSpectrum = 1;
	SampleArray frequencyBins;
	

	int VertexArray_x = -200;
	int VertexArray_y = 901;

	//affects how the spectrum and scrolling_spectrum are packed into the sfml window
	float x_max = 1200;
	float y_max = 1900;

	std::vector<ComplexVal> sample;
	std::vector<float> window;

	sf::VertexArray SpectrumView;
	sf::VertexArray ScrollingView;
	sf::VertexArray horiScrollingView;

	std::vector<sf::Vertex> scroll;
	std::vector<sf::Vertex> scrollHorizontal;
};