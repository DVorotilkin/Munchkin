using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MunchkinLib.Entities
{
	public class Monstr: Door
	{
		public int Level { get; private set; }
		public int Power { get; set; }
	}
}
