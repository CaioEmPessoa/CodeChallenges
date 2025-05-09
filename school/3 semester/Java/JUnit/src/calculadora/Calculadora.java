package calculadora;
import java.lang.Math;

public class Calculadora {

	public Object soma(double d, double e) {
		return d + e;
	}

	public Object subtrac(double d, double e) {
		return d - e;
	}
	
	public Object mult(double d, double e) {
		return d * e;
	}
	
	public Object div(double d, double e) {
		return d / e;
	}
	
	public Object pot(double d, double e) {
		return Math.pow(d, e);
	}
	
}
