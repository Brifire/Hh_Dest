#include "settingsmanager.h"
#include <QCoreApplication>
#include <QWidget>

SettingsManager::SettingsManager(QObject *parent)
    : QObject(parent),
    settings(QCoreApplication::organizationName(), QCoreApplication::applicationName())
{
}

SettingsManager& SettingsManager::instance()
{
    static SettingsManager instance;
    return instance;
}

void SettingsManager::setValue(const QString &key, const QVariant &value)
{
    settings.setValue(key, value);
}

QVariant SettingsManager::value(const QString &key, const QVariant &defaultValue) const
{
    return settings.value(key, defaultValue);
}

void SettingsManager::remove(const QString &key)
{
    settings.remove(key);
}

bool SettingsManager::contains(const QString &key) const
{
    return settings.contains(key);
}

void SettingsManager::saveWindowGeometry(const QString &prefix, QWidget *window)
{
    setValue(prefix + "/geometry", window->saveGeometry());
}

void SettingsManager::loadWindowGeometry(const QString &prefix, QWidget *window)
{
    window->restoreGeometry(value(prefix + "/geometry").toByteArray());
}

void SettingsManager::clearSettings()
{
    instance().settings.clear();
    instance().settings.clear();
}
