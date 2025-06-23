#include "../includes/Point.hpp"

bool BSP(Point const a, Point const b, Point const c, Point const point);

void printTest(const std::string& testName, bool expected, bool result) {
	std::cout << "Test: " << testName << " - " << RESET;
	if (result == expected) {
		std::cout << "✅ PASS";
	} else {
		std::cout << "❌ FAIL";
	}
	std::cout << " (Expected: " << (expected ? "true" : "false") 
			  << ", Got: " << (result ? "true" : "false") << ")" << std::endl;
}

int main() {
	std::cout << BLUE_BRIGHT << "=== TESTS BSP (Binary Space Partitioning) ===" << RESET << std::endl << std::endl;
	
	// Triangle de base pour la plupart des tests
	Point a(0.0f, 0.0f);    // Sommet A
	Point b(4.0f, 0.0f);    // Sommet B  
	Point c(2.0f, 3.0f);    // Sommet C
	
	std::cout << "Triangle principal: A(0,0), B(4,0), C(2,3)" << std::endl << std::endl;
	
	// === TESTS 1: Points clairement à l'intérieur ===
	std::cout << BLUE_BRIGHT << "--- Tests: Points à l'intérieur ---" << RESET << std::endl;
	Point inside1(2.0f, 1.0f);     // Centre du triangle
	Point inside2(1.0f, 0.5f);     // Proche du côté AB
	Point inside3(2.5f, 1.5f);     // Côté droit
	Point inside4(1.5f, 1.5f);     // Côté gauche
	
	printTest("Point au centre", true, BSP(a, b, c, inside1));
	printTest("Point proche AB", true, BSP(a, b, c, inside2));
	printTest("Point côté droit", true, BSP(a, b, c, inside3));
	printTest("Point côté gauche", true, BSP(a, b, c, inside4));
	
	// === TESTS 2: Points clairement à l'extérieur ===
	std::cout << BLUE_BRIGHT << std::endl << "--- Tests: Points à l'extérieur ---" << RESET << std::endl;
	Point outside1(-1.0f, 1.0f);   // À gauche du triangle
	Point outside2(5.0f, 1.0f);    // À droite du triangle
	Point outside3(2.0f, -1.0f);   // En dessous du triangle
	Point outside4(2.0f, 4.0f);    // Au dessus du triangle
	Point outside5(-2.0f, -2.0f);  // Très loin
	Point outside6(10.0f, 10.0f);  // Très loin
	
	printTest("Point à gauche", false, BSP(a, b, c, outside1));
	printTest("Point à droite", false, BSP(a, b, c, outside2));
	printTest("Point en dessous", false, BSP(a, b, c, outside3));
	printTest("Point au dessus", false, BSP(a, b, c, outside4));
	printTest("Point très loin (-)", false, BSP(a, b, c, outside5));
	printTest("Point très loin (+)", false, BSP(a, b, c, outside6));
	
	// === TESTS 3: Points sur les sommets (doivent retourner false) ===
	std::cout << std::endl << YELLOW << "--- Tests: Points sur les sommets ---" << RESET << std::endl;
	printTest("Point sur sommet A", false, BSP(a, b, c, a));
	printTest("Point sur sommet B", false, BSP(a, b, c, b));
	printTest("Point sur sommet C", false, BSP(a, b, c, c));
	
	// === TESTS 4: Points sur les côtés (doivent retourner false) ===
	std::cout << std::endl << YELLOW << "--- Tests: Points sur les côtés ---" << RESET << std::endl;
	Point onAB(2.0f, 0.0f);     // Milieu du côté AB
	Point onBC(3.0f, 1.5f);     // Milieu du côté BC
	Point onCA(1.0f, 1.5f);     // Milieu du côté CA
	Point onAB2(1.0f, 0.0f);    // Autre point sur AB
	Point onAB3(3.0f, 0.0f);    // Autre point sur AB
	
	printTest("Point sur côté AB (milieu)", false, BSP(a, b, c, onAB));
	printTest("Point sur côté BC (milieu)", false, BSP(a, b, c, onBC));
	printTest("Point sur côté CA (milieu)", false, BSP(a, b, c, onCA));
	printTest("Point sur côté AB (1/4)", false, BSP(a, b, c, onAB2));
	printTest("Point sur côté AB (3/4)", false, BSP(a, b, c, onAB3));
	
	// === TESTS 5: Triangle avec coordonnées négatives ===
	std::cout << std::endl << YELLOW << "--- Tests: Triangle avec coordonnées négatives ---" << RESET << std::endl;
	Point a2(-2.0f, -1.0f);
	Point b2(1.0f, -1.0f);
	Point c2(-0.5f, 2.0f);
	Point inside_neg(0.0f, 0.0f);     // À l'intérieur
	Point outside_neg(2.0f, 2.0f);    // À l'extérieur
	
	std::cout << "Triangle négatif: A(-2,-1), B(1,-1), C(-0.5,2)" << std::endl;
	printTest("Point à l'intérieur (coord neg)", true, BSP(a2, b2, c2, inside_neg));
	printTest("Point à l'extérieur (coord neg)", false, BSP(a2, b2, c2, outside_neg));
	
	// === TESTS 6: Triangle très petit ===
	std::cout << std::endl << YELLOW << "--- Tests: Triangle très petit ---" << RESET << std::endl;
	Point a3(0.0f, 0.0f);
	Point b3(0.1f, 0.0f);
	Point c3(0.05f, 0.1f);
	Point inside_small(0.05f, 0.03f);  // À l'intérieur
	Point outside_small(0.2f, 0.2f);   // À l'extérieur
	
	std::cout << "Triangle petit: A(0,0), B(0.1,0), C(0.05,0.1)" << std::endl;
	printTest("Point à l'intérieur (petit triangle)", true, BSP(a3, b3, c3, inside_small));
	printTest("Point à l'extérieur (petit triangle)", false, BSP(a3, b3, c3, outside_small));
	
	// === TESTS 7: Triangle avec ordre différent (sens horaire) ===
	std::cout << std::endl << YELLOW << "--- Tests: Triangle sens horaire ---" << RESET << std::endl;
	Point a4(0.0f, 0.0f);
	Point b4(2.0f, 3.0f);    // Ordre inversé pour sens horaire
	Point c4(4.0f, 0.0f);
	Point inside_clockwise(2.0f, 1.0f);
	
	std::cout << "Triangle horaire: A(0,0), B(2,3), C(4,0)" << std::endl;
	printTest("Point à l'intérieur (sens horaire)", true, BSP(a4, b4, c4, inside_clockwise));
	
	// === TESTS 8: Cas limites avec des coordonnées décimales ===
	std::cout << std::endl << YELLOW << "--- Tests: Coordonnées décimales ---" << RESET << std::endl;
	Point a5(0.5f, 0.5f);
	Point b5(2.7f, 0.3f);
	Point c5(1.2f, 2.8f);
	Point inside_decimal(1.5f, 1.2f);
	Point outside_decimal(3.0f, 3.0f);
	
	std::cout << "Triangle décimal: A(0.5,0.5), B(2.7,0.3), C(1.2,2.8)" << std::endl;
	printTest("Point à l'intérieur (décimaux)", true, BSP(a5, b5, c5, inside_decimal));
	printTest("Point à l'extérieur (décimaux)", false, BSP(a5, b5, c5, outside_decimal));
	
	// === RÉSUMÉ ===
	std::cout << std::endl << YELLOW << "=== FIN DES TESTS ===" << RESET << std::endl;
	std::cout << YELLOW << "Vérifiez que tous les tests passent ✓" << RESET << std::endl;
	std::cout << YELLOW << "Si certains échouent ✗, vérifiez votre implémentation BSP" << RESET << std::endl;
	
	return 0;
}