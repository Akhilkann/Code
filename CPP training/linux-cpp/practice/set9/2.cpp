#include<iostream>


class CItem
{
    int CItemID;
    int CItemPrice;
    public:
    CItem(int ID,int Price):CItemID(ID),CItemPrice(Price){}
    friend class CStock;
};
class CStock
{
    int ItemID;
    int ItemQuantity;
    double TotalPrice;

    public:
    friend class CItem;
    CStock(int ID,int Quantity):ItemID(ID),ItemQuantity(Quantity)
    {
        TotalPrice=0.0;
    }

    void calculatePrice(CItem& obj)
    {
        if(ItemID==obj.CItemID)
        {
            TotalPrice=obj.CItemPrice*ItemQuantity;
            std::cout<<"ItemID : "<<ItemID<<" Price : "<<obj.CItemPrice<<" ItemQuantity : "<<ItemQuantity<<" Total Price : "<<TotalPrice;
        }
    }



};

int main()
{
    CItem item(12,101);
    CStock stock(12,10);
    stock.calculatePrice(item);
    return 0;
}