

class StorageUnit extends Hardware {
    int capacity;
    String type;

    StorageUnit(String name, String manufacturer, double price, int capacity, String type) {
        super(name, manufacturer, price);
        this.capacity = capacity;
        this.type = type;
    }
}