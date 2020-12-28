import scala.io.StdIn

object Solution {
  def solve(person: String, wants: Int, g: Int, gP: Int, gPB: Int): (Int, Int, Int, Boolean) = {
    wants match {
      case 0 => (g, gP, gPB, true)
      case _ => {
        person match {
          case "Andrew" => {
            g match {
              case 0 => (g, gP, gPB, false)
              case _ => solve(person, wants - 1, g - 1, gP - 1, gPB - 1)
            }
          }
          case "Dmitry" => {
            gP match {
              case 0 => (g, gP, gPB, false)
              case _ => solve(person, wants - 1, g, gP - 1, gPB - 1)
            }
          }
          case "Michal" => {
            gPB match {
              case 0 => (g, gP, gPB, false)
              case _ => solve(person, wants - 1, g, gP, gPB - 1)
            }
          }
        }
      }
    }
  }
  def main(args: Array[String]): Unit = {
    val pw = List("Andrew", "Dmitry", "Michal").zip(StdIn.readLine().split(" ").map(x => x.toInt))
    val gPB = StdIn.readLine().split(" ").map(x => x.toInt)

    val g = gPB(0)
    val p = gPB(1)
    val b = gPB(2)

    val res = pw.foldLeft((g, g + p, g + p + b, true)) 
      { (acc, e) => 
        { 
          val lRes = solve(e._1, e._2, acc._1, acc._2, acc._3)
          (lRes._1, lRes._2, lRes._3, lRes._4 && acc._4)
        } 
      }
    res._4 match {
      case true => println("YES")
      case false => println("NO")
    }
  }
}
