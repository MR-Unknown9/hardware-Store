

class CoolingSystem extends Hardware {
    String type;

    CoolingSystem(String name, String manufacturer, double price, String type) {
        super(name, manufacturer, price);
        this.type = type;
    }
}
