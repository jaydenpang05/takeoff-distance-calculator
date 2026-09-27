// ProjectRunway.cpp : This project was done by Jayden Pang.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;
const double PI = 3.14159265, G = 9.81, dt = 0.01;

static double getPositiveNumber(string prompt, double minVal = 0.0) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value <= minVal) {
			cout << "Invalid input. Please enter a positive number greater than " << minVal << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	return value;
}

static double gete(string prompt, double minVal = 0.0) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value <= minVal || value > 1.0) {
			cout << "Invalid input. Please enter a positive number greater than " << minVal << " and less than or equal to 1." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	return value;
}

static double getZeroOrPositive(string prompt, double minVal = 0.0) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value < minVal) {
			cout << "Invalid input. Please enter a positive number greater than or equal to " << minVal << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	return value;
}

static double getTemperature(string prompt, double warnMin = -80, double warnMax = 60) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid number in degrees Celsius." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (value < warnMin || value > warnMax) {
			cout << "Warning: The entered temperature is outside the typical range of " << warnMin << " to " << warnMax << " degrees Celsius." << endl;
			cout << "Please confirm if you want to proceed with this value (y/n): ";
			char confirm;
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				break;
			}
			else if (confirm == 'n' || confirm == 'N') {
				cout << "Please enter a new temperature value." << endl;
				continue;
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				continue;
			}
		}
		else {
			break;
		}
	}
	return value;
}

static double getmass(string prompt, double minVal = 0.0, double warnMax = 1000000) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value <= minVal) {
			cout << "Invalid input. Please enter a positive number between " << minVal << " and " << warnMax << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else if (value > warnMax) {
			cout << "Warning: The entered mass is unusually high. Please confirm if you want to proceed with this value (y/n): ";
			char confirm;
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				break;
			}
			else if (confirm == 'n' || confirm == 'N') {
				cout << "Please enter a new mass value." << endl;
				continue;
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				continue;
			}
		}
		else {
			break;
		}
	}
	return value;
}

static double getCLmax(string prompt, double minVal = 0.0, double warnMax = 4) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value <= minVal) {
			cout << "Invalid input. Please enter a number greater than" << minVal << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else if (value > warnMax) {
			cout << "Warning: The entered CLmax value is unusually high. Please confirm if you want to proceed with this value (y/n): ";
			char confirm;
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				break;
			}
			else if (confirm == 'n' || confirm == 'N') {
				cout << "Please enter a new CLmax value." << endl;
				continue;
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				continue;
			}
		}
		else {
			break;
		}
	}
	return value;
}

static double getRH(string prompt, double minVal = 0, double maxVal = 100) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail() || value < minVal || value > maxVal) {
			cout << "Invalid input. Please enter a positive number between " << minVal << " and " << maxVal << "." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}
	}
	return value;
}

static double getaltitude(string prompt, double warnMin = -500, double warnMax = 10000) {
	double value;
	while (true) {
		cout << prompt;
		cin >> value;
		if (cin.fail()) {
			cout << "Invalid input. Please enter a valid number in meters." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (value < warnMin || value > warnMax) {
			cout << "Warning: The entered altitude is outside the typical range of " << warnMin << " to " << warnMax << " meters." << endl;
			cout << "Please confirm if you want to proceed with this value (y/n): ";
			char confirm;
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y') {
				break;
			}
			else if (confirm == 'n' || confirm == 'N') {
				cout << "Please enter a new altitude value." << endl;
				continue;
			}
			else {
				cout << "Invalid input. Please enter 'y' or 'n'." << endl;
				continue;
			}
		}
		else {
			break;
		}
	}
	return value;
}

static string getRunwayCondition(string prompt) {
	string condition;
	while (true) {
		cout << prompt;
		cin >> condition;
		if (condition == "dry" || condition == "wet" || condition == "icy") {
			return condition;
		}
		else {
			cout << "Invalid input. Please enter 'dry', 'wet', or 'icy'." << endl;
		}
	}
}



int main()
{
	double mass, thrust, S, b, h, CLmax, CD0, CDconfig, runwaylength, alt, tempC, rh, e, deratedinput; // input variables
	string runwaycondition, takeoffsafety;
	double tempK, P, Psat, Pv, rho, mew; // environment variables
	double CLto, AR, phi, CD, deratedthrust, thrustActual; // aircraft variables
	double weight, V, Vs, VLO, V_old; // performance variables
	double t, s, L, D, R, F, a; //simulation variables


	mass = getmass("Enter the mass of the aircraft (kg): ");
	thrust = getPositiveNumber("Enter the thrust of the engines (N): ");
	deratedinput = getRH("Enter the percentage of thrust used (%)");
	deratedthrust = thrust * (deratedinput / 100);
	S = getPositiveNumber("Enter the wing area (m^2): ");
	b = getPositiveNumber("Enter the wingspan (m): ");
	h = getPositiveNumber("Enter the height of the wing above the ground (m): ");
	CLmax = getCLmax("Enter the maximum lift coefficient (CLmax): ");
	CD0 = getZeroOrPositive("Enter the zero-lift drag coefficient (CD0): ");
	CDconfig = getZeroOrPositive("Enter the additional drag coefficient due to configuration (CDconfig): ");
	runwaycondition = getRunwayCondition("Enter the runway condition (dry/wet/icy): ");
	runwaylength = getPositiveNumber("Enter the runway length (m): ");
	alt = getaltitude("Enter the airport altitude (m): ");
	tempC = getTemperature("Enter the runway temperature (°C): ");
	rh = getRH("Enter the runway relative humidity (%): ");
	e = gete("Enter the Oswald efficiency factor (e): ");

	// set default value for mew to avoid uninitialized use
	mew = 0.02;
	if (runwaycondition == "dry") {
		mew = 0.02;
	}
	else if (runwaycondition == "wet") {
		mew = 0.05;
	}
	else if (runwaycondition == "icy") {
		mew = 0.08;
	}

	V = 0.0, a = 0.0, s = 0.0, t = 0.0; // initialize simulation variables
	weight = mass * G;// weight of the aircraft (W=mg)
	tempK = tempC + 273.15; // absolute temperature (K)
	P = 101325 * pow(1 - 0.0065 * alt / 288.15, 5.25588); // absolute pressure (Pa)
	Psat = 610.7 * pow(10, (7.5 * tempC / (tempC + 237.3))); // saturation vapor pressure (Pa)
	Pv = rh / 100 * Psat; // actual vapor pressure (Pa)
	rho = (P - Pv) / (287.05 * tempK) + Pv / (461.495 * tempK); // air density (kg/m^3)
	Vs = sqrt(2.0 * weight / (rho * S * CLmax)); // stall speed (m/s)
	VLO = 1.2 * Vs; // liftoff speed (m/s)
	phi = pow((16.0 * h / b), 2) / (1.0 + pow((16.0 * h / b), 2)); // ground effect factor
	AR = pow(b, 2) / S; // aspect ratio of wing

	while (V < VLO) {
		CLto = 0.8 * CLmax * (V / VLO); // lift coefficient during takeoff
		CD = CD0 + (phi * pow(CLto, 2) / (PI * AR * e)) + CDconfig; // drag coefficient during takeoff
		D = 0.5 * rho * pow(V, 2) * S * CD; // drag force (N)
		L = 0.5 * rho * pow(V, 2) * S * CLto; // lift force (N)
		R = mew * (weight - L); // rolling resistance (N)
		if (R < 0.0) {
			R = 0.0; // no negative rolling resistance
		}
		thrustActual = deratedthrust * (1.0 - 0.5 * (V / 340.0));
		F = thrustActual - R - D; // net force (N)
		a = F / mass; // acceleration (m/s^2)
		V_old = V;
		V += a * dt; // update velocity (m/s)
		s += 0.5 * (V_old + V) * dt; // update distance (m)
		t += dt; // update time (s)


		if (t > 300) { // safety check to prevent infinite loop
			cout << "Takeoff simulation exceeded 5 minutes. Please check the input parameters." << endl;
			return 1;
		}
	}
	if (s < 0.8 * runwaylength) {
		takeoffsafety = "Safe for takeoff";
	}
	else {
		takeoffsafety = "Unsafe for takeoff";
	}
	cout << fixed << setprecision(2);
	cout << "Takeoff speed: " << VLO << " m/s" << endl;
	cout << "Takeoff distance: " << s << " m" << endl;
	cout << "Takeoff time: " << t << " s" << endl;
	cout << "Takeoff safety: " << takeoffsafety << endl;
	return 0;


}


