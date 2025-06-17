/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:07:51 by faustoche         #+#    #+#             */
/*   Updated: 2025/06/17 23:20:23 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

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

///////////////`


// Fonction bsp (a, b, c, p)

// 1er produite = fonction de calcule de a, b, p
// 2			= fonction de calcul de b, c, p
// 3eme produit = fonction de calcul de c, a, p

// on verifie si P est sur un cote ou un sommet
	// si 1 == 0 ou 2 == 0 ou 2 == 0
		// value faux

// on verifie si tous les produits sont du meme signe (pos neg)
	// si 1 > 0 && 2>0 && 3>0
		//value = true
	// si 1<0 && 2<0 && 3<0
		//value = false
// return value


// Comment on calcule ?
// 