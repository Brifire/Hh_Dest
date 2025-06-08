#include "tabextendedmodel.h"
#include "Hh_Data_Structures/datastructures.h"

TabExtendedModel::TabExtendedModel(QObject *parent)
    : QAbstractItemModel(parent)
{}

QVariant TabExtendedModel::headerData(int section, Qt::Orientation orientation, int role) const
{

    if (role != Qt::DisplayRole)
        return {};
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "Мода";
        case 1: return "Медиана";
        case 2: return "Среднее";
        case 3: return "Навык";
        }
    }
    return {};
}

QModelIndex TabExtendedModel::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() || !m_SkillStat || row < 0 || column < 0 ||
        row >= static_cast<int>(m_SkillStat->size()) || column >= 4)
        return QModelIndex();
    return createIndex(row, column);
}

QModelIndex TabExtendedModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int TabExtendedModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
    return m_SkillStat->size();
    // FIXME: Implement me!
}

int TabExtendedModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;
    return 8;
}

QVariant TabExtendedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole || !m_SkillStat)
        return {};

    const SkillStat &job = m_SkillStat->at(index.row());

    switch (index.column()) {
    case 0: return job.moda;
    case 1: return job.mediana;
    case 2: return job.mean;
    case 3: return job.skill;
    default: return {};
    }
}

void TabExtendedModel::setDataList(const std::vector<SkillStat>& data)
{
    beginResetModel();
    *m_SkillStat=data;
    endResetModel();
}
