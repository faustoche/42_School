#include "../includes/Point.hpp"

bool BSP(Point const a, Point const b, Point const c, Point const point);

void print_result(const std::string& testName, bool expected, bool result)
{
	std::cout << testName << " - " << RESET;
	if (result == expected) {
		std::cout << GREEN << "✅ PASS" << RESET;
	} else {
		std::cout << RED << "❌ FAIL" << RESET;
	}
	std::cout << " (Expected: ";
	if (expected) {
		std::cout << "true";
	} else {
		std::cout << "false";
	}
	std::cout << " ,Got: ";
	if (result) {
		std::cout << "true";
	} else {
		std::cout << "false";
	}
	std::cout << ")" << std::endl;
}

int main() {
	std::cout << PINK << "=== TESTS BSP (Binary Space Partitioning) ===" << RESET << std::endl << std::endl;

	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(2.0f, 3.0f);
	std::cout << "Main triangle: A(0,0), B(4,0), C(2,3)" << std::endl;

	std::cout << CYAN << "\n*----- TEST 1 : INSIDE -----*" << RESET << std::endl << std::endl;
	Point inside1(2.0f, 1.0f); // Dans le triangle
	Point inside2(1.0f, 0.5f); // À coté de AB
	Point inside3(2.5f, 1.5f); // Droite
	Point inside4(1.5f, 1.5f); // Gcueh
	print_result("Point centered    ", true, BSP(a, b, c, inside1));
	print_result("Point close to AB ", true, BSP(a, b, c, inside2));
	print_result("Point on the right", true, BSP(a, b, c, inside3));
	print_result("Point on the left ", true, BSP(a, b, c, inside4));
	
	std::cout << GREEN << "\n*----- TEST 2 : OUTSIDE -----*" << RESET << std::endl << std::endl;
	Point outside1(-1.0f, 1.0f); // à gauche
	Point outside2(5.0f, 1.0f); // à droite
	Point outside3(2.0f, -1.0f); // en dessous
	Point outside4(2.0f, 4.0f); // au dessus
	Point outside5(-2.0f, -2.0f); // loin en négatif
	Point outside6(10.0f, 10.0f); // loin en positif
	print_result("Point on the left ", false, BSP(a, b, c, outside1));
	print_result("Point on the right", false, BSP(a, b, c, outside2));
	print_result("Point below       ", false, BSP(a, b, c, outside3));
	print_result("Point above       ", false, BSP(a, b, c, outside4));
	print_result("Point far away (-)", false, BSP(a, b, c, outside5));
	print_result("Point far away (+)", false, BSP(a, b, c, outside6));
	
	std::cout << ORANGE << "\n*----- TEST 3 : ON VERTEX (TOP) -----*" << RESET << std::endl << std::endl;
	print_result("Point on A vertex", false, BSP(a, b, c, a));
	print_result("Point on B vertex", false, BSP(a, b, c, b));
	print_result("Point on C vertex", false, BSP(a, b, c, c));

	std::cout << GOLD << "\n*----- TEST 4 : ON THE SIDE -----*" << RESET << std::endl << std::endl;
	Point onAB(2.0f, 0.0f); // milieu du côté AB
	Point onBC(3.0f, 1.5f); // milieu du côté BC
	Point onCA(1.0f, 1.5f); // Milieu du côté CA
	Point onAB2(1.0f, 0.0f); // autre point sur AB
	Point onAB3(3.0f, 0.0f); // autre point sur AB
	print_result("Point on AB (middle)", false, BSP(a, b, c, onAB));
	print_result("Point on BC (middle)", false, BSP(a, b, c, onBC));
	print_result("Point on CA (middle)", false, BSP(a, b, c, onCA));
	print_result("Point on AB (1/4)   ", false, BSP(a, b, c, onAB2));
	print_result("Point on AB (3/4)   ", false, BSP(a, b, c, onAB3));
	
	std::cout << FUCHSIA << "\n*----- TEST 5 : GOING DOWN DOWN DOWN (NEGATIVE COORDINATES) -----*" << RESET << std::endl << std::endl;
	Point a2(-2.0f, -1.0f);
	Point b2(1.0f, -1.0f);
	Point c2(-0.5f, 2.0f);
	Point inside_neg(0.0f, 0.0f);// intérieur
	Point outside_neg(2.0f, 2.0f);// extérieur
	std::cout << "Negative triangle: A(-2,-1), B(1,-1), C(-0.5,2)" << std::endl;
	print_result("Point inside (neg) ", true, BSP(a2, b2, c2, inside_neg));
	print_result("Point outside (neg)", false, BSP(a2, b2, c2, outside_neg));
	
	std::cout << TURQUOISE << "\n*----- TEST 6 : VERY SMALL TRIANGLE -----*" << RESET << std::endl << std::endl;
	Point a3(0.0f, 0.0f);
	Point b3(0.3f, 0.0f);
	Point c3(0.15f, 0.3f);
	Point inside_small(0.15f, 0.1f); // intérieur
	Point outside_small(0.5f, 0.5f); // extérieur
	std::cout << "Small triangle: A(0,0), B(0.1,0), C(0.05,0.1)" << std::endl;
	print_result("Point inside (small) ", true, BSP(a3, b3, c3, inside_small));
	print_result("Point outside (small)", false, BSP(a3, b3, c3, outside_small));
	
	std::cout << MAGENTA << "\n*----- TEST 7 : DECIMAL COORDINATES -----*" << RESET << std::endl << std::endl;
	Point a5(0.5f, 0.5f);
	Point b5(2.7f, 0.3f);
	Point c5(1.2f, 2.8f);
	Point inside_decimal(1.5f, 1.2f); // intérieur
	Point outside_decimal(3.0f, 3.0f); // exterieur
	std::cout << "Decimal triangle: A(0.5,0.5), B(2.7,0.3), C(1.2,2.8)" << std::endl;
	print_result("Point inside (decimal) ", true, BSP(a5, b5, c5, inside_decimal));
	print_result("Point outside (decimal)", false, BSP(a5, b5, c5, outside_decimal));
	
	std::cout << std::endl << PINK << "=== END OF TESTS ===" << RESET << std::endl;
	return 0;
}