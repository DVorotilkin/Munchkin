using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MunchkinLib.Entities
{
	enum BodyParts //собстно на что шмот то одевать
	{
		Head,
		Hands,
		Foots,
		Body
	}

	public class Player
	{
		public List<Races> Races { get; set; }
		public List<Classes> PlayerClass { get; set; }
		public int Level { get; set; }
		public int Power { get; set; }
		public int Lucky { get; set; }
		private bool _superMunchkin;
		private bool _raceCoctail;
	}

//	public class Player
//	{
        
//		private List<Race> _races;
//		private List<Class> _classes;
//		private List<Ability> _ability; //для всяких куриц на башне
//		private List<Card> hand;
//		private byte _damage { get; }
//		public List<Shmatte> _shmattes;
//		public bool _gender;
//		public byte _lvl;
//		public bool _superMunchkin;
//		public bool _raceCoctail;
//		public List<Race> getRaces()
//		{
//			return _races;
//		}

//		public void replaceRace(Race oldRace, Race newRace)
//		{
//			int i;
//			if ((i = _races.IndexOf(oldRace)) != -1)
//				_races[i] = newRace;
//		}

//		public List<Class> getClasses()
//		{
//			return _classes;
//		}

//		public void replaceClass(Class oldClass, Class newClass)
//		{
//			int i;
//			if ((i = _classes.IndexOf(oldClass)) != -1)
//				_classes[i] = newClass;
//		}

//		public List<Ability> getAbilitys()
//		{
//			return _ability;
//		}

//		public void addAbilitys(Ability ability)
//		{
//			_ability.Add(ability);
//		}
//	}
}
