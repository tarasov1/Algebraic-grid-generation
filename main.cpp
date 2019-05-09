#include "Curvebase.hpp"
#include "CurveTop.hpp"
#include "CurveBottom.hpp"
#include "CurveLeft.hpp"
#include "CurveRight.hpp"
#include "Domain.hpp"

int main(){

    Curvebase *side1 = new CurveBottom(-10, 5);
    Curvebase *side2 = new CurveRight(0, 3, 5);
    Curvebase *side3 = new CurveTop(-10, 5, 3);
    Curvebase *side4 = new CurveLeft(0, 3, -10);

    Domain d = Domain(*side1, *side2, *side3, *side4);
    d.generateGrid(50,20);
    d.writeToFile();
}
        
