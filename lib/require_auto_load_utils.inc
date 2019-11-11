<?php

/**
 * Description of auto_load_utils
 *
 * @author Jessé Rafael das Neves
 */
class RequireAutoLoadUtils {

    public function autoLoadNamespace(string $className) {
        $oFactoryAutoLoad = new FactoryFileAutoLoadClass($className);
        $oFactoryAutoLoad->setDirectoryLevels(3);
        $oFactoryAutoLoad->toExtensionInc();
        $oFactoryAutoLoad->setBaseDirectory(FileUtils::DIR_INCLUDE);
        $oFactoryAutoLoad->requireFileIfExists();
    }

    public function autoLoadClass(string $className) {
        $oFactoryAutoLoad = new FactoryFileAutoLoadClass($className);
        $oFactoryAutoLoad->setDirectoryLevels(3);
        $oFactoryAutoLoad->toExtensionInc();
        $oFactoryAutoLoad->setBaseDirectory(FileUtils::DIR_LIBRARIES);
        $oFactoryAutoLoad->requireFileIfExists();
    }

    public function autoLoadJwsBean(string $className) {
        $oFactoryAutoLoad = new FactoryFileAutoLoadClass($className);
        $oFactoryAutoLoad->setDirectoryLevels(3);
        $oFactoryAutoLoad->setBaseDirectory(FileUtils::DIR_LIBRARIES);
        $oFactoryAutoLoad->addDirectory(FileUtils::DIR_LIB_JWSBEAN);
        $oFactoryAutoLoad->requireFileIfExists();
    }

    public function autoLoadJwsQuery(string $className) {
        $oFactoryAutoLoad = new FactoryFileAutoLoadClass($className);
        $oFactoryAutoLoad->setDirectoryLevels(3);
        $oFactoryAutoLoad->setBaseDirectory(FileUtils::DIR_LIBRARIES);
        $oFactoryAutoLoad->addDirectory(FileUtils::DIR_LIB_JWSQUERY);
        $oFactoryAutoLoad->requireFileIfExists();
    }

}
