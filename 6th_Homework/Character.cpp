#include "Character.h"

// https://www.w3schools.com/cpp/cpp_constructors.asp - konstruktors
// Konstruktors: inicializē vārdu, dzīvību, spēku, zobenu un vairogu
Character::Character(string n, int l, int s, int sw_weight, int sw_quality, int sh_size, int sh_protection)
    : name(n), life((l > 0) ? l : 1), strength(s), sw(sw_weight, sw_quality), sh(sh_size, sh_protection) {
    for (int i = 0; i < 10; i++) path[i] = '-';
}

// Samazina dzīvību
bool Character::Hit(int damage) {
    if (life > 0) {
        life -= damage;
        if (life < 0) life = 0;
    }
    return life > 0;
}

int Character::Attack() {
    return (life > 0) ? strength + sw.Damage() : 0;
}

int Character::Defence() {
    return (life > 0) ? (strength / 2) + sh.Block() : 0;
}

int Character::GetLife() const {
    return life;
}

void Character::Go(char direction) {
    if (life > 0 && (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd')) {
        for (int i = 8; i >= 0; i--) path[i + 1] = path[i];
        path[0] = direction;
    }
}

void Character::SetLife(int l) { life = l; }
void Character::AddLife(int l) { life += l; }

string Character::GetName() const { return name; }

// Drukā informāciju par personāžu
void Character::Print() {
    cout << "Name: " << name << endl;
    cout << "Status: " << (life > 0 ? "Alive (" + to_string(life) + " HP)" : "Dead") << endl;
    cout << "Path: ";
    for (char c : path) cout << c;
    cout << endl;
    cout << "Sword - Weight: " << sw.GetWeight() << ", Quality: " << sw.GetQuality() << endl;
    cout << "Shield - Size: " << sh.GetSize() << ", Protection: " << sh.GetProtection() << endl;
}

// Destruktors
Character::~Character() {
    cout << "Game over for " << name << endl;
}

// Ievades operators (>>) 
istream& operator>>(istream& in, Character& ch) {
    cout << "Ievadi vārdu, dzīvību, spēku: ";
    in >> ch.name >> ch.life >> ch.strength;
    return in;
}

// Izvades operators (<<)
ostream& operator<<(ostream& out, const Character& ch) {
    out << "Name: " << ch.name << ", Life: " << ch.life << ", Strength: " << ch.strength;
    return out;
}

// Piešķiršanas operators (=)
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        life = other.life;
        strength = other.strength;
        for (int i = 0; i < 10; i++) path[i] = other.path[i];
        sw = other.sw;
        sh = other.sh;
    }
    return *this;
}

// ++ Prefikss (palielina dzīvību par 1)
Character& Character::operator++() {
    life++;
    return *this;
}

// ++ Postfikss (kopē veco, palielina dzīvību
Character Character::operator++(int) {
    Character temp = *this;
    life++;
    return temp;
}

// Prefikss -- (samazina dzīvību, ja > 0)
Character& Character::operator--() {
    if (life > 0) life--;
    return *this;
}

// Postfiksa -- (kopē veco, samazina dzīvību, ja > 0)
Character Character::operator--(int) {
    Character temp = *this;
    if (life > 0) life--;
    return temp;
}

// Salīdzināšana pēc life * strength
bool Character::operator<(const Character& other) const {
    return (life + strength) < (other.life + other.strength);
}
bool Character::operator>(const Character& other) const {
    return (life + strength) > (other.life + other.strength);
}
bool Character::operator<=(const Character& other) const {
    return !(*this > other);
}
bool Character::operator>=(const Character& other) const {
    return !(*this < other);
}
bool Character::operator==(const Character& other) const {
    return (life + strength) == (other.life + other.strength);
}
bool Character::operator!=(const Character& other) const {
    return !(*this == other);
}