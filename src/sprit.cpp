#include "sprit.h"

std::map<string, Sprit*> Sprit::vectorSprit = std::map<string, Sprit*>();

Sprit::Sprit() {}

Sprit::Sprit(string _typeUnit)
{
    listImage = std::vector<Image*>();

    string fileName = "data/units/" + _typeUnit + "/";
    Image* image;

    vectorSprit[_typeUnit] = this;
    for (int i = 0; i<NMB_COLOR; i++)
    {
        image = new Image(fileName + std::to_string(i) + ".png");
        listImage.push_back(image);
    }
}

Sprit::~Sprit() {}

Image* Sprit::getImage(int _owner)
{
    return listImage[_owner%NMB_COLOR];
}

Image* Sprit::getImageUnit(string _typeUnit, int _owner)
{
    return vectorSprit[_typeUnit]->getImage(_owner);
}
