#include "musiccategoryconfigmanager.h"

MusicCategoryConfigManager::MusicCategoryConfigManager(QObject *parent)
    : TTKAbstractXml(parent)
{

}

bool MusicCategoryConfigManager::fromFile(Category type)
{
    QString v;
    switch(type)
    {
        case Category::PlayList: v = ":/data/playlist"; break;
        case Category::TopList: v = ":/data/toplist"; break;
        case Category::ArtistList: v = ":/data/artistlist"; break;
        case Category::MovieList: v = ":/data/movielist"; break;
        default: break;
    }

    return TTKAbstractXml::fromFile(v);
}

void MusicCategoryConfigManager::readBuffer(MusicResultsCategoryList &items, const QString &key)
{
    const QDomNodeList &nodes = m_document->elementsByTagName(key);
    for(int i = 0; i < nodes.count(); ++i)
    {
        const QDomNode &node = nodes.at(i);
        const QDomNodeList &tagNodes = node.childNodes();
        for(int j = 0; j < tagNodes.count(); ++j)
        {
            MusicResultsCategory category;
            const QDomNode &tagNode = tagNodes.at(j);
            category.m_category = tagNode.toElement().attribute("value");
            const QDomNodeList &typeNodes = tagNode.childNodes();
            for(int k = 0; k < typeNodes.count(); ++k)
            {
                MusicResultsCategoryItem item;
                const QDomNode &typeNode = typeNodes.at(k);
                item.m_key = typeNode.toElement().attribute("key");
                item.m_value = typeNode.toElement().attribute("value");
                category.m_items.append(item);
            }
            items.append(category);
        }
    }
}
