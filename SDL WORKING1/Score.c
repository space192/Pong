#include "graphics.h"

void ScoresJoueurUn(int ScoreJoueurUn)
{
	POINT CentreScoreJoueurUn;
	
	CentreScoreJoueurUn.x = 300; CentreScoreJoueurUn.y = 580;
	aff_int(ScoreJoueurUn, 50, CentreScoreJoueurUn, blanc);


}

void ScoresJoueurDeux(int ScoreJoueurDeux)
{
	POINT CentreScoreJoueurDeux;

	CentreScoreJoueurDeux.x = 500; CentreScoreJoueurDeux.y = 580;
	aff_int(ScoreJoueurDeux, 50, CentreScoreJoueurDeux, blanc);
}