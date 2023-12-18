import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class StorageSystem {
    List<Hardware> hardwareList;
    int cpuCount, gpuCount, ramCount, storageUnitCount, motherboardCount, powerSupplyCount, coolingSystemCount,
            caseCount, peripheralCount;

    StorageSystem() {
        this.hardwareList = new ArrayList<>();
        this.cpuCount = 0;
        this.gpuCount = 0;
        this.ramCount = 0;
        this.storageUnitCount = 0;
        this.motherboardCount = 0;
        this.powerSupplyCount = 0;
        this.coolingSystemCount = 0;
        this.caseCount = 0;
        this.peripheralCount = 0;

    }

    void add() {
        Hardware hardware = null;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the piece name: ");
        String name = input.nextLine();
        System.out.println("Enter manufacturer name: ");
        String manu = input.nextLine();
        double price;
        while (true) {
            System.out.println("Enter price: ");
            String nprice = input.nextLine();

            try {
                price = Double.parseDouble(nprice);
                break;
            } catch (NumberFormatException e) {
                System.out.println("Invalid input! Enter a number please.");
            }
        }

        System.out.println("Note: Please write without any spaces!");
        System.out.println("Enter hardware type: ");
        String type = input.nextLine().toLowerCase(); // Convert to lowercase for case-insensitivity

        switch (type) {
            case "cpu": {
                int cores;
                while (true) {
                    System.out.println("Enter number of cores: ");
                    String ncores = input.nextLine();

                    try {
                        cores = Integer.parseInt(ncores);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                double freq;
                while (true) {
                    System.out.println("Enter frequency : ");
                    String nfreq = input.nextLine();

                    try {
                        freq = Double.parseDouble(nfreq);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new CPU(name, manu, price, cores, freq);
                break;
            }
            case "gpu": {
                int memory;
                while (true) {
                    System.out.println("Enter gpu memory: ");
                    String nmemory = input.nextLine();

                    try {
                        memory = Integer.parseInt(nmemory);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new GPU(name, manu, price, memory);
                break;
            }
            case "ram": {
                int memory;
                while (true) {
                    System.out.println("Enter memory: ");
                    String nmemory = input.nextLine();

                    try {
                        memory = Integer.parseInt(nmemory);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                int speed;
                while (true) {
                    System.out.println("Enter speed: ");
                    String nspeed = input.nextLine();

                    try {
                        speed = Integer.parseInt(nspeed);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                hardware = new RAM(name, manu, price, memory, speed);
                break;
            }
            case "storageunit": {
                int size;
                while (true) {
                    System.out.println("Enter size: ");
                    String nsize = input.nextLine();
                    try {
                        size = Integer.parseInt(nsize);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                System.out.println("Enter type: ");
                String stype = input.nextLine();
                hardware = new StorageUnit(name, manu, price, size, stype);
                break;
            }
            case "motherboard": {
                System.out.println("Enter model: ");
                String model = input.nextLine();
                hardware = new Motherboard(name, manu, price, model);
                break;
            }
            case "powersupply": {
                int wattage;
                while (true) {
                    System.out.println("Enter wattage: ");
                    String nwattage = input.nextLine();

                    try {
                        wattage = Integer.parseInt(nwattage);
                        break;
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input! Enter a number please.");
                    }
                }
                System.out.println("Enter efficiency: ");
                String eff = input.nextLine();
                hardware = new PowerSupply(name, manu, price, wattage, eff);
                break;
            }
            case "coolingsystem": {
                System.out.println("Enter type: ");
                String ctype = input.nextLine();
                hardware = new CoolingSystem(name, manu, price, ctype);
                break;
            }
            case "case": {
                System.out.println("Enter size: ");
                String size = input.nextLine();
                System.out.println("Enter color: ");
                String color = input.nextLine();
                hardware = new Case(name, manu, price, size, color);
                break;
            }
            case "peripheral": {
                System.out.println("Enter connection type: ");
                String con = input.nextLine();
                System.out.println("Enter Peripheral type: ");
                String ptype = input.nextLine();
                hardware = new Peripheral(name, manu, price, con, ptype);
                break;
            }
            default: {
                System.out.println("Invalid hardware type!");
                break;
            }
        }

        if (hardware != null) {
            this.hardwareList.add(hardware);
            System.out.println("Hardware added successfully!");
        }
        input.close();
    }

    void removeHardwareByName(String name) {
        Hardware hardwareToRemove = null;

        for (Hardware hardware : hardwareList) {
            if (hardware.name.equals(name)) {
                hardwareToRemove = hardware;
                break;
            }
        }

        if (hardwareToRemove != null) {
            hardwareList.remove(hardwareToRemove);
            System.out.println("Removed hardware with name: " + name);
        } else {
            System.out.println("Hardware with name " + name + " not found.");
        }
    }

    Hardware search(String name) {
        for (Hardware hardware : this.hardwareList) {
            if (hardware.name.equals(name)) {
                return hardware;
            }
        }
        return null;
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
    }

    public int count() {
        return this.hardwareList.size();
    }

    void countHardwareByType() {
        for (Hardware hardware : this.hardwareList) {
            if (hardware instanceof CPU) {
                cpuCount++;
            } else if (hardware instanceof GPU) {
                gpuCount++;
            } else if (hardware instanceof RAM) {
                ramCount++;
            } else if (hardware instanceof StorageUnit) {
                storageUnitCount++;
            } else if (hardware instanceof Motherboard) {
                motherboardCount++;
            } else if (hardware instanceof PowerSupply) {
                powerSupplyCount++;
            } else if (hardware instanceof CoolingSystem) {
                coolingSystemCount++;
            } else if (hardware instanceof Case) {
                caseCount++;
            } else if (hardware instanceof Peripheral) {
                peripheralCount++;
            }
        }

        System.out.println("CPU: " + cpuCount);
        System.out.println("GPU: " + gpuCount);
        System.out.println("RAM: " + ramCount);
        System.out.println("Storage Unit: " + storageUnitCount);
        System.out.println("Motherboard: " + motherboardCount);
        System.out.println("Power Supply: " + powerSupplyCount);
        System.out.println("Cooling System: " + coolingSystemCount);
        System.out.println("Case: " + caseCount);
        System.out.println("Peripheral: " + peripheralCount);
    }
}
