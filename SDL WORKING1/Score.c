#include "graphics.h"

void Scores(int ScorePartie)
{
	POINT CentreScore;
	
	CentreScore.x = 300; CentreScore.y = 580;
	aff_int(ScorePartie, 50, CentreScore, blanc);


}