enum class VehicleSize { Motorcycle, Compact, Medium, Large};

class Vehicle;
class Level;

class ParkingSpot {
public:
    ParkingSpot (Level *lv, int r, int c, VehicleSize sz): _level(lv), _row(r), _col(c), _spotSize(s) {};
    bool isAvailable() { return _vehicle == nullptr;};
    bool canFitVehicle(Vehicle *v) { return _spotSize >= v->_size;};
    bool park(Vehicle * v) { _vehicle = v};
    bool leave() { _vehicle = nullptr};
    int getRow() { return _row; };
    int getCol() { return _col; };


private:
    Vehicle *_vehicle = nullptr;
    VehicleSize _spotSize;
    int _row;
    int _col;
    Level *_level = nullptr;
}

class Vehicle {
public:
    Vehicle() {};
    
private:
    vector<ParkingSpot> _parkingSpots;
    string _license;
    int _spotNeeded;
    VehicleSize _size;
}

class Bus: public Vehicle {
public:
    Bus () {
        _spotNeeded = 5;
        _size = VehicleSize::Large;
    }
}

class Car: public Vehicle {
public:
    Car () {
        _spotNeeded = 1;
        _size = VehicleSize::Compact;
    }
}

class Morotcycle: public Vehicle {
public:
    Morotcycle () {
        _spotNeeded = 1;
        _size = VehicleSize::Motorcycle;
    }
}

class Level {
public:
    Level() {}
    Level(int floor, int numberOfSpots): _floor(floor), _availableSpots(numberOfSpots) {}
    level(const Level* lv) {
        *this = *lv;
    }
    bool parkVehicle(Vehicle v) {};

private:
    int _floor;
    vector<ParkingSpot> _spots;
    int _availableSpots = 0;
    static const int _SPOTS_PER_ROW = 10;
    int findAvailableSpotsFor(Vehicle v) {};
}

class ParkingLot {
public:
    ParkingLot() {} 
    bool parkVehicle(Vehicle vehicle) {} 

private:
    vector<Level> _levels;
    const int _NUM_LEVELS = 5;
};