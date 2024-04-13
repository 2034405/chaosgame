// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

Vector2f midpointcalc(Vector2f first, Vector2f second){
    Vector2f midPoint;
    midPoint.x = (first.x + second.x)/2;
    midPoint.y = (first.y + second.y)/2;
    return midPoint; 
}

int main()
{
    srand(time(NULL));
    // Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber Game!!", Style::Default);

    vector<Vector2f> vertices;
    vector<Vector2f> points;

	while (window.isOpen())
	{
        /*
		****************************************
		Handle the players input
		****************************************
		*/
        Event event;
		while (window.pollEvent(event))
		{
            if (event.type == Event::Closed)
            {
				// Quit the game when the window is closed
				window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;

                    if(vertices.size() < 3)
                    {
                        vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
                    }
                    else if(points.size() == 0)
                    {
                        ///fourth click
                        ///push back to points vector
                        Vector2f currentpos;
                        currentpos.x = event.mouseButton.x;
                        currentpos.y = event.mouseButton.y;
                        points.push_back(currentpos);
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
        /*
		****************************************
		Update
		****************************************
		*/

        if(points.size() > 0)
        {
            ///generate more point(s)
            ///select random vertex
            ///calculate midpoint between random vertex and the last point in the vector
            ///push back the newly generated coord.
            int chooserVar = rand()%3;
            Vector2f spotNew;
            spotNew = midpointcalc(vertices[chooserVar],points[points.size()-1]);
            points.push_back(spotNew);
        }

        /*
		****************************************
		Draw
		****************************************
		*/
        window.clear();
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(vertices[i].x, vertices[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
        for(int i=0;i<points.size();i++){
            RectangleShape rect(Vector2f(10,10));
            rect.setPosition(Vector2f(points[i].x, points[i].y));
            rect.setFillColor(Color::Blue);
            window.draw(rect);
        }
        window.display();
    }
}