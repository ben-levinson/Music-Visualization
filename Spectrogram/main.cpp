//#include "FFT.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Spectrogram.h"
#include <iostream>


int main()
{
	std::string path;
	int FFTSize = 1;
	std::cout << "Place .wav audio file in the Sound directory of this executable" << std::endl;
	std::cout << "Enter name of audio file followed by .wav: ";
	std::cin >> path;

	do
	{
		std::cout << "Enter the FFT size (must be a power of 2.) This determines the number of bins used (16384 recommended): ";
		std::cin >> FFTSize;
	} while (FFTSize % 2 != 0);
	CooleyTukeyFFT fft("./Sound/" + path, FFTSize);
	Spectrogram s(fft);

	sf::Event evnt;
	sf::RenderWindow window(sf::VideoMode(1200, 900, 32), "Spectrograms");

	int debounceCount = 0;
	int keyUpCount = 0;
	bool pressed = false;
	while (window.isOpen())
	{
		while (window.pollEvent(evnt)) {}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !pressed)
		{
			debounceCount++;
			if(debounceCount == 5)
			{
				s.ToggleDisp();
				debounceCount = 0;
				pressed = true;
			}
		}
		
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			keyUpCount++;
			if (keyUpCount >= 5)
			{
				keyUpCount = 0;
				pressed = false;
			}
		}
		
		s.update();
		window.clear();
		s.draw(window);
		window.display();
	}

	window.close();
	return 0;
}