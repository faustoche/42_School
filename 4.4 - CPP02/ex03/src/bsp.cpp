#include "../includes/Point.hpp"

/*
** p1 et p2 = vecteurs | p3 = point recherché
** Formule : crossProduct = (vecteur1.x * vecteur2.y) - (vecteur1.y * vecteur2.x)
** Résultat > 0 : p3 est à gauche de la ligne p1->p2
** Résultat < 0 : p3 est à droite de la ligne p1->p2
** Résultat = 0 : p3 est sur la ligne p1->p2
*/

Fixed	productCalculus(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed dx1 = p2.getX() - p1.getX();
	Fixed dy1 = p2.getY() - p1.getY();

	Fixed dx2 = p3.getX() - p1.getX();
	Fixed dy2 = p3.getY() - p1.getY();

	return (dx1 * dy2 - dy1 * dx2);
}

/*
** Utilisation du produit vectorial pour trouver le côté du point recherché
** Vecteur AB = (B.x - A.x, B.y - A.y);
** Vecteur AP = (P.x - A.x, P.y - A.y);
** Vérification des 3 côtés car le point doit être à l'intérieur de chaque arrête
** Point sur un côté = faux | Point sur un sommet = faux
*/

bool	BSP(Point const a, Point const b, Point const c, Point const point)
{
	Fixed product1 = productCalculus(a, b, point);
	Fixed product2 = productCalculus(b, c, point);
	Fixed product3 = productCalculus(c, a, point);

	if (product1 == 0 || product2 == 0 || product3 == 0)
		return (false);
	else if ((product1 > 0 && product2 > 0 && product3 > 0) ||
			(product1 < 0 && product2 < 0 && product3 < 0))
		return (true);
	else
		return (false);
}
