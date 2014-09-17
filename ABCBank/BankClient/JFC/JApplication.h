#ifndef _JAPPLICATION_H_
#define _JAPPLICATION_H_
namespace JFC{
	class JWindow;
	class JApplication
	{
	public:
		JApplication();
		~JApplication();

		static JApplication* Instance(){return self_;}
		void ShowCursor()const;
		void HideCursor()const;
		JWindow* GetCurrent()const{
			return current_;
		}
		void SetCurrent(JWindow* win){
			current_ = win;
		}
		JWindow* Root()const {
			return root_;
		}
		int Exec();

	private:
		static JApplication* self_;
		JWindow* current_;
		JWindow* root_;
	};
#define JApp JApplication::Instance()
}
#endif//_JAPPLICATION_H_