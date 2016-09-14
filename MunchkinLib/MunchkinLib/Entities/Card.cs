using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MunchkinLib.Entities
{
	/**
	 @class Содержит описание карт
	 */
	abstract class Card
	{
		public Player Owner { get; set; }
		public String Name { get; private set; }
		public String Description { get; private set; }
	}
}
