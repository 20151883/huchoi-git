class ISquad
{
	private:
		ISpaceMarine **arr;
		int size;
		int count;
	public:
		ISquad() :size = 50, count = 1
		{
			arr = new (*ISpaceMarine[size]);
		}
		ISquad(ISquad &src)
		{

		}
		ISquad &operator=(ISquad &src)
		{

		}

		virtual ~ISquad()
		{
			//all ISpace will be destroy
		}
		virtual int getCount() const = 0;
		virtual ISpaceMarine* getUnit(int) const = 0;
		virtual int push(ISpaceMarine*) = 0;
};
