#include <iostream>

using namespace std;

class Coordinate
{
    public :
        Coordinate (float xCoor, float yCoor) {
            xSet(xCoor);
            ySet(yCoor);
        }

        void xSet (float input){
            x = input;
        }

        void ySet (float input){
            y = input;
        }


        float xGet (){
            return x;
        }

        float yGet (){
            return y;
        }

    private :
        float x;
        float y;
};

string check (Coordinate thePlace, float magnification);
float power (float number, float exponent);
bool CheckBoxes (float magnification, Coordinate thePlace);
bool checkTriangle (float magnification, Coordinate thePlace);
bool distToPillar (float magnification, Coordinate thePlace, int triangleNo);
bool withinRange (Coordinate thePlace, Coordinate thePillar, float magnification);

int main()
{
    float numberOfLines;
    float magnification;
    float subX;
    float subY;

    while (true){
        cin >> numberOfLines;

        for (int i = 0;i < numberOfLines; i++ ) {
            cin >> magnification >> subX >> subY;
            Coordinate thePlace (subX + 1, subY + 1);

            cout << check (thePlace, magnification) << endl;
        }
    }
    return 0;
}

string check (Coordinate thePlace, float magnification) {
    string answer;
    bool validation = false;

    if (CheckBoxes(magnification, thePlace))
    {
        validation = true;
    }
    else if (checkTriangle(magnification, thePlace)) {
        validation = true;
    }

    if (validation == true){
        answer = "crystal";
    }

    else {
        answer = "empty";
    }

    return answer;
}

bool CheckBoxes (float magnification, Coordinate thePlace) {
    bool validation = false;
    float squareSize = power (5, magnification)/5;


    Coordinate initalBoundaryRec (squareSize,1);
    Coordinate finalBoundaryRec (4 * squareSize, squareSize);

    Coordinate initalBoundarySquare (2 * squareSize, squareSize);
    Coordinate finalBoundarySquare (3 * squareSize, 2 * squareSize);

    // cout << initalBoundaryRec.xGet()  << " " << finalBoundaryRec.xGet() << " " << initalBoundaryRec.yGet()  << " " << finalBoundaryRec.yGet() << endl;
    // cout << initalBoundarySquare.xGet()  << " " << finalBoundarySquare.xGet() << " " << initalBoundarySquare.yGet()  << " " << finalBoundarySquare.yGet() << endl;

    if  (thePlace.xGet() > initalBoundaryRec.xGet() && thePlace.xGet() <= finalBoundaryRec.xGet() &&
         thePlace.yGet() >= initalBoundaryRec.yGet() && thePlace.yGet() <= finalBoundaryRec.yGet()){
            validation = true;
        }

    else if (thePlace.xGet() > initalBoundarySquare.xGet() && thePlace.xGet() <= finalBoundarySquare.xGet() &&
            thePlace.yGet() >= initalBoundarySquare.yGet() && thePlace.yGet() <= finalBoundarySquare.yGet()){
            validation = true;
    }

    return validation;
}

bool checkTriangle (float magnification, Coordinate thePlace) {
    float squareSize = power (5, magnification)/5;
    float pillarHeight = (squareSize-1)/2;
    bool validation = false;

    //cout << pillarHeight << endl;

    if (thePlace.yGet() <= (squareSize * 2 + pillarHeight)){
        if (thePlace.xGet() > squareSize + 1 && thePlace.xGet() < squareSize * 2 &&
            thePlace.yGet() <= pillarHeight + squareSize &&
            distToPillar(magnification, thePlace, 1)){
            validation = true;
        }
        else if (thePlace.xGet() > squareSize*2 + 1 && thePlace.xGet() < squareSize * 3 &&
                 thePlace.yGet() <= pillarHeight + squareSize*2 &&
                 distToPillar(magnification, thePlace, 2)){
            validation = true;
        }
        else if (thePlace.xGet() > squareSize*3 + 1 && thePlace.xGet() < squareSize * 4 &&
                 thePlace.yGet() <= pillarHeight + squareSize &&
                 distToPillar(magnification, thePlace, 3)){
            validation = true;
        }

    }

    return validation;
}

bool distToPillar (float magnification, Coordinate thePlace, int triangleNo) {
    bool validation = true;
    float squareSize = power (5, magnification)/5;

    Coordinate thePillar (0,0);
    thePillar.xSet(triangleNo*squareSize + (squareSize+1)/2);

    if (triangleNo == 1 || triangleNo == 3){
        thePillar.ySet(squareSize + 1);
    }
    else {
        thePillar.ySet(squareSize*2 + 1);
    }

    // cout << thePillar.xGet() << " " << thePillar.yGet() << endl;

    if (withinRange (thePlace, thePillar, magnification)) {
        validation = true;
    }

    return validation;
}

bool withinRange (Coordinate thePlace, Coordinate thePillar, float magnification) {
    bool validation;
    float squareSize = power (5, magnification)/5;
    float validDistance ((squareSize + 1)/2 - (thePlace.yGet()- (thePillar.yGet()-1)));
    float theDistance = thePlace.xGet() - thePillar.xGet();

    if (theDistance < 0){
        theDistance *= -1;
    }

    if (theDistance < validDistance) {
        validation = true;
    }

    return validation;
}

float power (float number, float exponent) {
    float result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= number;
    }

    return result;
}
