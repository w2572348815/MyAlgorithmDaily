package MySBCode;

public class Test{
	public static void main(String args[]){
	 CPU cpu=new CPU();
	 HardDisk HD=new HardDisk();
	 cpu.setSpeed(2200);
	 HD.setAmount(200);
	 PC pc=new PC();
	 pc.setCPU(cpu);
	 pc.setHardDisk(HD);
	 pc.show();
	}


   
   }
   class PC{
	CPU cpu;
	HardDisk HD;
	void setCPU(CPU cpu){
	  this.cpu=cpu;
	}
	void setHardDisk(HardDisk HD){
	  this.HD=HD; 
	}
  void show(){
	System.out.println("CPU速度："+cpu.getSpeed());
	System.out.println("硬盘容量："+HD.getAmount());
	}
  }
  class CPU{
	int speed;
	int  getSpeed(){
	   return speed;
   }
   public void setSpeed(int speed){
	   this.speed=speed;
   }
 }
 class HardDisk{
	int amount;
	int getAmount(){
	  return amount;
	 }
	public void setAmount(int amount){
	  this.amount=amount;
	}
  }
  