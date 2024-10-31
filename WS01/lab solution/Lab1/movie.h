//Gil Feldman, 176428217, gfeldman@myseneca.ca

//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SENECA_MOVIE_H_
#define SENECA_MOVIE_H_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
namespace seneca {

	struct Movie {
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};
	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}
#endif // !SENECA_MOVIE_H_


