using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MunchkinLib.Entities
{
	public enum Races
	{
		AnyRace, //любая расса (для шмота)
		Man,
		Elf,
		Dwarf,
		Halfling
	};

	public class Race: Door
	{
		public Races value { get; private set; }
	}
}
