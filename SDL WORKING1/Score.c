#include "graphics.h"

void ScoresJoueurUn(int ScoreJoueurUn)
{
	POINT CentreScoreJoueurUn;
	POINT basDroitJoueurUn;
	POINT hautGaucheJoueurUn;
	
	CentreScoreJoueurUn.x = 300; CentreScoreJoueurUn.y = 680;
	basDroitJoueurUn.x = CentreScoreJoueurUn.x - 50;
	basDroitJoueurUn.y = CentreScoreJoueurUn.y - 55;
	hautGaucheJoueurUn.x = CentreScoreJoueurUn.x + 50;
	hautGaucheJoueurUn.y = CentreScoreJoueurUn.y + 50;

	draw_fill_rectangle(basDroitJoueurUn, hautGaucheJoueurUn, noir);
	aff_int(ScoreJoueurUn, 50, CentreScoreJoueurUn, blanc);


}

void ScoresJoueurDeux(int ScoreJoueurDeux)
{
	POINT CentreScoreJoueurDeux;
	POINT basDroitJoueurDeux;
	POINT hautGaucheJoueurDeux;

	CentreScoreJoueurDeux.x = 500; CentreScoreJoueurDeux.y = 680;
	basDroitJoueurDeux.x = CentreScoreJoueurDeux.x - 50;
	basDroitJoueurDeux.y = CentreScoreJoueurDeux.y - 55;
	hautGaucheJoueurDeux.x = CentreScoreJoueurDeux.x + 50;
	hautGaucheJoueurDeux.y = CentreScoreJoueurDeux.y + 50;

	draw_fill_rectangle(basDroitJoueurDeux, hautGaucheJoueurDeux, noir);
	aff_int(ScoreJoueurDeux, 50, CentreScoreJoueurDeux, blanc);
}