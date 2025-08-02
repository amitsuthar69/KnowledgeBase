abstract class Vehicle {
  abstract void accelerate();
  abstract void brake();

  void startEngine() {
    System.out.println("Engine started!");
  }
}

class Car extends Vehicle {
  @Override
  void accelerate() {
    System.out.println("Car: Pressing gas pedal...");
  }

  void brake() {
    System.out.println("Car: Pressing brakes...");
  }
}

public class Main {
  public static void main(String []args) {
    Vehicle myCar = new Car();
    myCar.startEngine();
    myCar.accelerate();
    myCar.brake();
  }
}