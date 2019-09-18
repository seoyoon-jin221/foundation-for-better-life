#include "Board.h"
#include <unistd.h>

Board::Board() {
	// create window to use for graphics
	m_window.create(sf::VideoMode(600, 875), "Drunk Driver", sf::Style::Close | sf::Style::Resize);
}

Board::~Board() {

}

void Board::drawBoard() {
    for (int i = 0; i < m_lanes.size(); i++) {
        for (int j = 0; j < m_lanes[0].size(); i++) {
            m_lanes[i][j]->draw(i,j,m_window);
        }
    }
    m_player.draw(m_playerPosition, m_window);

// each GameObject item needs a draw() function
// that will tell the board how to draw the item
// Player class also needs a draw function
}

void Board::update() {
    std::shared_ptr<GameObject> obj = nullptr;
    for (int i = 0; i < 3; i++) {
        obj = m_lanes[m_playerPosition].back();
        m_lanes[i].pop_back();
    }
    obj->influencePlayer(m_player);
    m_distance++;
    if (m_distance == 100 || m_distance == 200)
        m_level++;
    m_score += m_level;
    m_gameObjectGenerator.feedItem(m_lanes); // change the implementation to passing a pointer to the m_lanes
}

std::string Board::checkStatus() {
    if(m_player.isDead())
        return "Player Dead";
    if(!m_player.hasGas())
        return "Player has no Gas";
    if(m_player.isDrunk())
        return "Player Drunk";
    else
        return "okay";
    
}

void Board::setPlayerPosition(int pos) {
    m_playerPosition = pos;
}

void Board::gameOver() {
    m_window.clear();
    sf::RectangleShape kenta(sf::Vector2f(750,750));
    kenta.setPosition(0,0);
    sf::Texture kentaTexture;
    kentaTexture.loadFromFile("ripKenta.jpeg");
    kenta.setTexture(&kentaTexture);
    m_window.draw(kenta);
    
    usleep(30000000);
}

void Board::setPlayerStatus(bool drunk) {
    m_player.setDrunkState(drunk);
}

int Board::getPlayerPosition() const {
    return m_playerPosition;
}

int Board::getScore() const {
    return m_score;
}

int Board::getDistance() const {
    return m_distance;
}

const std::deque<std::deque<std::shared_ptr<GameObject > > >& Board::getLanes() const {
    return m_lanes;
}

void Board::setPlayerPosition(int pos) {
    m_playerPosition = pos;
}
