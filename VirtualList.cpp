#include "VirtualList.h"
#include <iostream>
VirtualList::VirtualList(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size)
    :wxListCtrl(parent, id, pos, size, wxLC_REPORT | wxLC_VIRTUAL) {


    Data = new LinkedList();
    UndoList = new LinkedList();
    Search = new LinkedList();
    Search_mode = false;

    wxListItem col0;
    col0.SetId(0);
    col0.SetText( wxT("Название") );
    col0.SetWidth(300);
    this->InsertColumn(0, col0);

    // Add second column
    wxListItem col1;
    col1.SetId(1);
    col1.SetText( wxT("Автор") );
    col1.SetWidth(300);
    this->InsertColumn(1, col1);

    // Add third column
    wxListItem col2;
    col2.SetId(2);
    col2.SetText( wxT("Год выпуска") );
    col2.SetWidth(100);
    this->InsertColumn(2, col2);

    wxListItem col3;
    col3.SetId(3);
    col3.SetText( wxT("Кол-во страниц") );
    col3.SetWidth(120);
    this->InsertColumn(3, col3);

    this->Bind(wxEVT_LIST_COL_CLICK, [this](wxListEvent &evt) {
        if(this->Data->size > 1){
            this->sort_by_col(evt.GetColumn());
            this->RefrashAfterUpdate();
        }
    });

}
void VirtualList::sort_by_col(int n) {
    if(Data->GetSort_by() != n) {
        this->Data->sort(n);
        Revers = false;
    }
        Revers = not(Revers);
}
void VirtualList::RefrashAfterUpdate() {
    this->SetItemCount(Data->size);
    this->Refresh();
}
void VirtualList::Add(std::string name,std::string auther,std::string year,std::string pages) {
    if(Search_mode){
        std::swap(Data,Search);
        Search->clear();
        Search_mode = false;
    }
    Data->insert(name,auther,year,pages);
}
long VirtualList::GetFirstSelectedIndex() {
    return GetNextItem(-1,wxLIST_NEXT_ALL,wxLIST_STATE_SELECTED);

}
void VirtualList::find(wxCommandEvent& event) {
    if (event.GetString() == "")
        return;
    if (Search_mode) {
        std::swap(Data,Search);
        Search->clear();
    }
    find(event.GetString().utf8_string());
    if(Search->size == 0)
        return;
    std::swap(Data,Search);
    Search_mode = true;
    this->RefrashAfterUpdate();
}
void VirtualList::Clear_search(wxCommandEvent& event) {
    if (Search_mode)
        std::swap(Data,Search);
    Search->clear();
    Search_mode = false;
    RefrashAfterUpdate();
}

void VirtualList::find(std::string search_by) {
    std::cout <<search_by;
    if(Data->size == 0)
        return;
    Node *current = Data->Begin();
    while(current != nullptr){
        if(current->name == search_by || current->auther == search_by || current->year == search_by || current->pages == search_by){
            Search->insert(current);
        }
        current = current->next;
    }
}
void VirtualList::Remove(long index){
    if (index < 0)
        return;
    if (Revers)
        index = Data->size-index-1;
    auto item = Data->GetByPos(index,false);
    if (Search_mode){
        auto current = Search->Begin();
        while(current != nullptr) {
            if(current->name == item->name && current->auther == item->auther && current->year == item->year && current->pages == item->pages){
                Search->remove(current);
                break;
            }
            current = current->next;
        }
    }
    UndoList->append(item->name,item->auther,item->year,item->pages);
    Data->remove(item);
    if (Data->size ==0) {
        std::swap(Data,Search);
        Search_mode = false;
    }
}
void VirtualList::Undo(wxCommandEvent &event) {
    if (UndoList->size == 0)
        return;
    auto item = UndoList->GetByPos(0,true);
    Add(item->name,item->auther,item->year,item->pages);
    UndoList->pop();
    RefrashAfterUpdate();
}
void VirtualList::GetFromFile(const char *string) {
    tinyxml2::XMLDocument doc;
    if(doc.LoadFile(string) == 0) {
        std::string name,auther,year,pages;
        auto element = doc.FirstChildElement() ->FirstChildElement();
        while(element!=nullptr){
            name = element->FirstChildElement("name")->GetText();
            auther = element->FirstChildElement("auther")->GetText();
            year = element->FirstChildElement("year")->GetText();
            pages = element->FirstChildElement("pages")->GetText();
            Add(name,auther,year,pages);
            element = element->NextSiblingElement();
        }
    }
    RefrashAfterUpdate();
}
void VirtualList::GenFile(const char *string) {
    if (Data->size >0){
        tinyxml2::XMLDocument doc;
        doc.Parse(
        "<books>"
        "</books>");
        auto current = Data->Begin();
        auto book = doc.FirstChildElement();
        auto el = book->ToElement();
        while (current != nullptr){
            el = book->InsertNewChildElement("book");
            el->InsertNewChildElement("name")->SetText(current->name.c_str());
            el->InsertNewChildElement("auther")->SetText(current->auther.c_str());
            el->InsertNewChildElement("year")->SetText(current->year.c_str());
            el->InsertNewChildElement("pages")->SetText(current->pages.c_str());
            current = current->next;
        }
        doc.SaveFile(string);
    }
}
