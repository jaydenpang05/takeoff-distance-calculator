# takeoff-distance-calculator
A C++ program that estimates aircraft takeoff distance and runway safety using aerodynamic and physics-based calculations (lift, drag, thrust lapse, air density from altitude/temperature/humidity).

## What it does

Given aircraft specs (mass, thrust, wing dimensions, lift/drag coefficients) and environmental conditions (runway length, weather, altitude, temperature, humidity), the program simulates the takeoff roll second-by-second and outputs:
- Estimated takeoff distance
- Time to liftoff
- Takeoff speed
- Whether the runway is long enough (with a 20% safety buffer)

## How it works

The simulation numerically integrates the aircraft's motion using Newton's second law:
Net Force = Thrust − Rolling Resistance − Drag


Key physics modeled:
- **Lift & Drag**: `L = ½ρV²S·C_L`, `D = ½ρV²S·C_D`, with induced drag, ground effect, and configuration drag accounted for
- **Air density**: derived from user-input altitude, temperature, and humidity via the ideal gas law
- **Rolling resistance**: scales with runway condition (dry/wet/icy) and decreases as lift increases
- **Thrust lapse**: thrust decreases slightly as airspeed increases, modeled with a simplified lapse constant
- **Numerical integration**: velocity via Euler's method, distance via the trapezoidal rule (dt = 0.01s)

The aircraft is considered airborne once V reaches liftoff speed (`V_LO = 1.2 × stall speed`).

## Assumptions

- Level, paved runway in average condition
- Constant thrust direction, aircraft weight, and takeoff configuration throughout the roll
- No engine spool-up delay, mechanical failures, or obstacles
- Simplified aerodynamics — not a full flight-dynamics simulation

*(Full assumptions and derivations are in the report PDF included in this repo.)*

## How to run
g++ main.cpp -o takeoff
./takeoff

You'll be prompted to enter aircraft mass, thrust, wing area, wingspan, wing height, CL_max, CD0, CD_config, Oswald efficiency, and runway/environment conditions.

## Sample output
Enter aircraft mass (kg): 60000
...
Takeoff distance: 1450 m
Takeoff time: 32.4 s
Takeoff speed: 78 m/s
Runway status: SAFE


## What I learned

This was a self-directed project built early in my C++ learning journey. Along the way I worked through modeling real physical assumptions correctly (e.g. discovering that CL,TO isn't actually constant through the roll, and correcting for thrust lapse with airspeed), validating simulation output against expected aircraft performance, and using numerical methods (Euler's method, trapezoidal rule) to approximate motion computationally.

## Sources

- [Takeoff/landing performance factors — ERAU](https://eaglepubs.erau.edu/introductiontoaerospaceflightvehicles/chapter/takeoff-landing-performance/)
- EUROCONTROL BADA Manual (CD0 reference)
- [Density of air — Wikipedia](https://en.wikipedia.org/wiki/Density_of_air)
