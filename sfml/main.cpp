#include <SFML/Graphics.hpp>
#include <sstream>

int main() {
    
    sf::RenderWindow window(sf::VideoMode(400, 300), "—четчик нажатий на кружочек");

   
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(150, 75); 

    int counter = 0;

    
    sf::Font font;
    font.loadFromFile("arial.ttf");
        
       
    

    
    sf::Text counterText;
    counterText.setFont(font);
    counterText.setCharacterSize(24);
    counterText.setFillColor(sf::Color::Black);
    counterText.setPosition(10, 10);

   
    auto updateText = [&]() {
        std::stringstream ss;
        ss << "Number of clicks: " << counter;
        counterText.setString(ss.str());
        };
    updateText();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();

           
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if (circle.getGlobalBounds().contains(mousePos)) {
                        counter++;
                        updateText();
                    }
                }
            }
        }

       
        window.clear(sf::Color::White);
        window.draw(circle);
        window.draw(counterText);
        window.display();
    }

    return 0;
}
