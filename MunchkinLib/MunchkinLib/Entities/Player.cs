using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace MunchkinLib
{
    public enum Race
    {
        AnyRace, //любая расса (для шмота)
        Man,
        Elf,
        Dwarf,
        Halfling
    };

    public enum Class
    {
        NoClass,
        Thief,
        Wizard,
        Warrior,
        Cleric
    };
    
    enum Body //собстно на что шмот то одевать
    {
        Head,
        Hands,
        Foots,
        Chest, //грудь - найдешь удачнее переименуй
    }

    public enum Ability //способности (подрезка, чит и тд)
    {

    }

    abstract class Card
    {

    }
    public class Shmatte //шмотка
    {
        Race _rase;
        Class _class;
        byte _bonus;
        Ability _ability;
        Body _body;
    }
    public class Player
    {
        
        private List<Race> _races;
        private List<Class> _classes;
        private List<Ability> _ability; //для всяких куриц на башне
        private List<Card> hand;
        private byte _damage { get; }
        public List<Shmatte> _shmattes;
        public bool _gender;
        public byte _lvl;
        public bool _superMunchkin;
        public bool _raceCoctail;
        public List<Race> getRaces()
        {
            return _races;
        }

        public void replaceRace(Race oldRace, Race newRace)
        {
            int i;
            if ((i = _races.IndexOf(oldRace)) != -1)
                _races[i] = newRace;
        }

        public List<Class> getClasses()
        {
            return _classes;
        }

        public void replaceClass(Class oldClass, Class newClass)
        {
            int i;
            if ((i = _classes.IndexOf(oldClass)) != -1)
                _classes[i] = newClass;
        }

        public List<Ability> getAbilitys()
        {
            return _ability;
        }

        public void addAbilitys(Ability ability)
        {
            _ability.Add(ability);
        }
    }
}
