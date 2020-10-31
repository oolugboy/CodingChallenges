import scala.io.StdIn

object Solution {
  def fact(n: Int): Int = {
    n match {
      case 0 => 1
      case _ => n * fact(n - 1)
    }
  }
  def pow(n: Double, exp: Int): Double = {
    exp match  {
      case 0 => 1
      case _ => n * pow(n, exp - 1)
    }
  }
  def expSeries(x: Double, terms: Int = 10): Double = {
    terms match  {
      case 1 => 1
      case _ => (pow(x, terms - 1)/ fact(terms - 1)) + expSeries(x, terms - 1)
    }
  }
  def readInput(amount: Int): List[Double] = {
    amount match  {
      case 0 => List[Double]()
      case _ => StdIn.readDouble()::readInput(amount - 1)
    }
  }
  def main(args: Array[String]): Unit = {
    val amount = StdIn.readInt()
    readInput(amount).map(x => expSeries(x)).map(res => println(f"$res%.4f"))
  }
}
