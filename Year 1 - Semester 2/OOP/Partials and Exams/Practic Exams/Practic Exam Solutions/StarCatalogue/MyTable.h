#pragma once

#include "Service.h"
#include <QAbstractTableModel>
#include <QMessageBox>

class MyTable : public QAbstractTableModel{
private:
    vector<Star> arr;
public:
    MyTable(const vector<Star> &arr);
    int rowCount(const QModelIndex& parent = QModelIndex{}) const override;

    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const override;
    
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex& index)const;

    void update(vector<Star>& new_arr);


};

