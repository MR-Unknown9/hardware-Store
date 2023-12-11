import java.util.*;

class StorageSystem {
    List<Hardware> hardwareList;

    StorageSystem() {
        this.hardwareList = new ArrayList<>();
    }

    void display() {
        for (Hardware hardware : this.hardwareList) {
            String type = "Unknown";
            if (hardware instanceof CPU) {
                type = "CPU";
                CPU cpu = (CPU) hardware;
                System.out
                        .println("NAME: " + cpu.name + ", TYPE: " + type + ", PRICE: " + cpu.price + ", MANUFACTURER: "
                                + cpu.manufacturer + ", CORES: " + cpu.cores + ", FREQUENCY: " + cpu.frequency);
            } else if (hardware instanceof GPU) {
                type = "GPU";
                GPU gpu = (GPU) hardware;
                System.out.println("NAME: " + gpu.name + ", TYPE: " + type + ", PRICE: " + gpu.price
                        + ", MANUFACTURER: " + gpu.manufacturer + ", MEMORY: " + gpu.memory);
            } else if (hardware instanceof RAM) {
                type = "RAM";
                RAM ram = (RAM) hardware;
                System.out
                        .println("NAME: " + ram.name + ", TYPE: " + type + ", PRICE: " + ram.price + ", MANUFACTURER: "
                                + ram.manufacturer + ", CAPACITY: " + ram.capacity + ", SPEED: " + ram.speed);
            } else if (hardware instanceof StorageUnit) {
                type = "Storage Unit";
                StorageUnit storageUnit = (StorageUnit) hardware;
                System.out.println("NAME: " + storageUnit.name + ", TYPE: " + type + ", PRICE: " + storageUnit.price
                        + ", MANUFACTURER: " + storageUnit.manufacturer + ", CAPACITY: " + storageUnit.capacity
                        + ", TYPE: " + storageUnit.type);
            } else if (hardware instanceof Motherboard) {
                type = "Motherboard";
                Motherboard motherboard = (Motherboard) hardware;
                System.out.println("NAME: " + motherboard.name + ", TYPE: " + type + ", PRICE: " + motherboard.price
                        + ", MANUFACTURER: " + motherboard.manufacturer + ", MODEL: " + motherboard.model);
            } else if (hardware instanceof PowerSupply) {
                type = "Power Supply";
                PowerSupply powerSupply = (PowerSupply) hardware;
                System.out.println("NAME: " + powerSupply.name + ", TYPE: " + type + ", PRICE: " + powerSupply.price
                        + ", MANUFACTURER: " + powerSupply.manufacturer + ", WATTAGE: " + powerSupply.wattage
                        + ", EFFICIENCY: " + powerSupply.efficiency);
            } else if (hardware instanceof CoolingSystem) {
                type = "Cooling System";
                CoolingSystem coolingSystem = (CoolingSystem) hardware;
                System.out.println("NAME: " + coolingSystem.name + ", TYPE: " + type + ", PRICE: " + coolingSystem.price
                        + ", MANUFACTURER: " + coolingSystem.manufacturer + ", TYPE: " + coolingSystem.type);
            } else if (hardware instanceof Case) {
                type = "Case";
                Case caseHardware = (Case) hardware;
                System.out.println("NAME: " + caseHardware.name + ", TYPE: " + type + ", PRICE: " + caseHardware.price
                        + ", MANUFACTURER: " + caseHardware.manufacturer + ", SIZE: " + caseHardware.size + ", COLOR: "
                        + caseHardware.color);
            } else if (hardware instanceof Peripheral) {
                type = "Peripheral";
                Peripheral peripheral = (Peripheral) hardware;
                System.out.println("NAME: " + peripheral.name + ", TYPE: " + type + ", PRICE: " + peripheral.price
                        + ", MANUFACTURER: " + peripheral.manufacturer + ", TYPE: " + peripheral.type + ", CONNECTION: "
                        + peripheral.connection);
            }
        }

        // add john
        // remove manassa
        // count john karam
        // search behoy
        // sort khaled
    }
}
