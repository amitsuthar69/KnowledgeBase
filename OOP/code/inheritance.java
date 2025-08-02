// Single inheritnce
public class Animal {
  void speak() {
    System.out.println("The Animal speaks");
  }
}

public class Dog extends Animal {
  // method over-riding
  @Override
  void speak() { 
    System.out.println("The Dog barks");
  }
}

// ----------------------------------------

// Multi-level inheritance
class Vehicle {
  Vehicle() {
  System.out.println("This is a Vehicle");
  }
}

class FourWheeler extends Vehicle {
  FourWheeler() {
    System.out.println("4 Wheeler Vehicles");
  }
}

class Car extends FourWheeler {
  Car() {
    System.out.println("This 4 Wheeler Vehicle is a Car");
  }
}

public class Geeks {
  public static void main(String[] args) {
    Car obj = new Car(); // Triggers all constructors in order
  }
}

// -------------------------------------------

// Hierarchial Inheritance

class Vehicle {
  Vehicle() {
    System.out.println("This is a Vehicle");
  }
}

class Car extends Vehicle {
  Car() {
    System.out.println("This Vehicle is Car");
  }
}

cass Bus extends Vehicle {
  Bus() {
    System.out.println("This Vehicle is Bus");
  }
}

public class Test {
  public static void main(String[] args) {
    Car obj1 = new Car(); 
    Bus obj2 = new Bus(); 
  }
}

// ---------------------------------------

// Multiple Inheritance

interface LandVehicle {
  default void landInfo() {
    System.out.println("This is a LandVehicle");
  }
}

interface WaterVehicle {
  default void waterInfo() {
    System.out.println("This is a WaterVehicle");
  }
}

// Subclass implementing both interfaces
class AmphibiousVehicle implements LandVehicle, WaterVehicle {
  AmphibiousVehicle() {
    System.out.println("This is an AmphibiousVehicle");
  }
}

public class Test {
  public static void main(String[] args) {
    AmphibiousVehicle obj = new AmphibiousVehicle();
    obj.waterInfo();
    obj.landInfo();
  }
}