using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MunchkinLib.Entities
{
	public enum Classes
	{
		NoClass,
		Thief,
		Wizard,
		Warrior,
		Cleric
	};

	public class Class: Door
	{
		public Classes value { get; private set; }
	}
}
