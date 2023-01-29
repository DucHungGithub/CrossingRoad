#pragma once
#include <cstdlib>

class TrafficLight
{
public:
    
    TrafficLight(sf::Texture& texturedendo, sf::Texture& texturedenxanh, float positionx,float positiony)
    {
        timeStart = rand() % 300 + 750;
        timeStop = 0;
        switches = false;
        dendo = texturedendo;
        denxanh = texturedenxanh;
        trafficLight.setTexture(texturedenxanh);
        trafficLight.setPosition({ positionx,positiony });

    }
    bool checkStop()
    {
        return switches;
    }
    void update()
    {
        switch (switches)
        {
        case false:
            timeStart -= 1;
            if (timeStart == 0)
            {

                timeStop = rand() % 100 + 100;
                trafficLight.setTexture(dendo);
                switches = true;
            }
            break;
        case true:
            timeStop -= 1;
            if (timeStop == 0)
            {

                timeStart = rand() % 300 + 750;
                trafficLight.setTexture(denxanh);
                switches = false;
            }
            break;
        default:
            break;
        }
    }
    void setTexture(sf::Texture& texture)
    {
        trafficLight.setTexture(texture);
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(trafficLight);
    }
private:
    sf::Texture dendo;
    sf::Texture denxanh;
    sf::Sprite trafficLight;
    int timeStop;
    int timeStart;
    bool switches;
};
