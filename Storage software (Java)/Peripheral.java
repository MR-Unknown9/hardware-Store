

class Peripheral extends Hardware {
    String type;
    String connection;

    Peripheral(String name, String manufacturer, double price, String type, String connection) {
        super(name, manufacturer, price);
        this.type = type;
        this.connection = connection;
    }
}