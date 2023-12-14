

class Motherboard extends Hardware {
    String model;

    Motherboard(String name, String manufacturer, double price, String model) {
        super(name, manufacturer, price);
        this.model = model;
    }
}