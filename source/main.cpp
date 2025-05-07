#include <SFML/Graphics.hpp>
#include "../include/jeu.hpp"
#include <iostream>
#include <unistd.h>

const int WINDOW_SIZE = 800;
const int GRID_SIZE = 40;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;

void drawGrid(sf::RenderWindow& window, Jeu& sim) {
    // Clear the window
    window.clear(sf::Color::White);
    
    // Draw each cell
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            Coord currentCoord(i, j);
            std::string intermediate  = sim.lettreCase(currentCoord);
            char cellContent = intermediate[0];
            
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);
            
            // Set color based on cell content
            if (cellContent == 'R') {
                cell.setFillColor(sf::Color::Red);    
            } else if (cellContent == 'L') {
                cell.setFillColor(sf::Color::Green);  
            } else {
                cell.setFillColor(sf::Color::White);  
            }
            
            window.draw(cell);
        }
    }
    
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Ecosystem Simulation");
    window.setFramerateLimit(60);
    
    Jeu simulation(0.1, 0.5);
    int ntours = 100;
    
    while (window.isOpen() && ntours > 0) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        drawGrid(window, simulation);
        
        simulation.joueTour();
        ntours--;
        
        std::cout << "Tour numero: " << ntours << std::endl;
        std::cout << "========================================================================================" << std::endl; 
        std::cout << std::endl;
        
        sf::sleep(sf::milliseconds(1000));
    }
    
    return 0;
}