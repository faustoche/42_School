/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:07:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/18 21:58:58 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// p1 = point de depart
// p2 = deuxieme point (vectuer avec p1)
// p3 = troisieme (le point a tester)
// formule math: Cross Product = (vecteur1.x × vecteur2.y) - (vecteur1.y × vecteur2.x)
/*
Résultat > 0 : p3 est à gauche de la ligne p1→p2 (sens trigonométrique)
Résultat < 0 : p3 est à droite de la ligne p1→p2
Résultat = 0 : p3 est sur la ligne p1→p2
*/

Fixed	productCalculus(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed dx1 = p2.getX() - p1.getX();
	Fixed dy1 = p2.getY() - p1.getY();

	Fixed dx2 = p3.getX() - p1.getX();
	Fixed dy2 = p3.getY() - p1.getY();

	return (dx1 * dy2 - dy1 * dx2);
}

// Pour savoir de quel cote se trouve un point : produit vectoriel
// Pour une ligne de A à B et un point P:
	// vecteur AB = (B.x - A.x, B.y - A.y);
	// Vecteur AP = (P.x - A.x, P.y - A.y);
	// Prduit en croix = AB.x x AP.y - AB.y x AP.x

// Interpretation des resultats:
	// PC > 0 = P est a gauche de AB
	// PC < 0 = P est a droite de AB
	// PC = 0 = P est sur AB

// On verifie les 3 cotes du triange car un point est a l'interieur exclusivement si est du meme cot ede chaque qrrete
// Si le point est sur un cote (=0) alors faux
// Si le point est sur un sommet alors faux

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
