

class PowerSupply extends Hardware {
    int wattage;
    String efficiency;

    PowerSupply(String name, String manufacturer, double price, int wattage, String efficiency) {
        super(name, manufacturer, price);
        this.wattage = wattage;
        this.efficiency = efficiency;
    }
}
