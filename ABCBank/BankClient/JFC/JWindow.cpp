#include "JWindow.h"
#include "JEvent.h"
#include <algorithm>
using namespace JFC;
JWindow::JWindow()
:parent_(0),
canFocus_(false)
{
}
JWindow::JWindow(SHORT x,SHORT y,SHORT width,SHORT height,JWindow* parent)
:JWindowBase(x,y,width,height),parent_(parent),canFocus_(false){
	if(parent_){
		parent_->AddChild(this);
	}
}
JWindow::~JWindow()
{
	if(parent_){
		parent_->DelChild(this);
	}
}
void JWindow::OnKeyEvent(JEvent* e){
	if(!e -> IsDone()){
		if(parent_){
			parent_->OnKeyEvent(e);
		}
	}
}
void JWindow::Draw(){
	SetTextColor(FCOLOR_BLACK);
	SetBkColor(BCOLOR_WHITE);
	JRECT rect = {0,0,Width()-1,Height()-1};
	FillRect(rect);
}
void JWindow::Show(){
	SetCurrent();
	Draw();
	Refresh();
}
void JWindow::AddChild(JWindow* win){
	childs_.push_back(win);
}
void JWindow::DelChild(JWindow* win){
	childs_.erase(std::remove(childs_.begin(),childs_.end(),win),childs_.end());
}

void JWindow::SetCurrent(){
	if(IsCurrent()){
		return;
	}
	if(canFocus_)
		JApp->SetCurrent(this);
	else{
		std::vector<JWindow*>::const_iterator it;
		for(it=childs_.begin();it!=childs_.end();++it){
			if((*it)->IsCurrent()){
			//if((*it)->canFocus_){
				break;
			}
		}
		if(it ==  childs_.end()){
			JWindow* win = FindFirst();
			if(win)
				JApp->SetCurrent(win);
			else{
				JApp->SetCurrent(this);
			}
		}
	}
}

JWindow* JWindow::FindFirst(){
	JWindow* p = NULL;
	std::vector<JWindow*>::const_iterator it;
	for(it=childs_.begin();it!=childs_.end();++it){
		if((*it)->canFocus_){
			p = *it;
			break;
		}
	}
	return p;
}
JWindow* JWindow::FindLast(){
	JWindow* p = NULL;
	std::vector<JWindow*>::const_reverse_iterator ri;
	for(ri=childs_.rbegin();ri!=childs_.rend();++ri){
		if((*ri)->canFocus_){
			p = *ri;
			break;
		}
	}
	return p;
}
JWindow* JWindow::FindPrev(JWindow* win){
	JWindow* p = NULL;
	std::vector<JWindow*>::const_reverse_iterator ri;
	ri = std::find(childs_.rbegin(),childs_.rend(),win);
	if(ri == childs_.rend())
		return NULL;
	if(*ri == FindFirst())
		p = FindLast();
	else{
		++ri;
		for(;ri!=childs_.rend();++ri){
			if((*ri)->canFocus_){
				p = *ri;
				break;
			}
		}
	}
	return p;
}
JWindow* JWindow::FindNext(JWindow* win){
	JWindow* p = 0;
	std::vector<JWindow*>::const_iterator it;
	it = std::find(childs_.begin(),childs_.end(),win);
	if(it == childs_.end())
		return NULL;
	if(*it == FindLast())
		p = FindFirst();
	else{
		++it;
		for(;it!=childs_.end();++it){
			if((*it)->canFocus_){
				p = *it;
				break;
			}
		}
	}
	return p;
}