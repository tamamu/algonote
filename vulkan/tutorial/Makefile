VULKAN_SDK_PATH = /Users/tamamu/Lib/VulkanSDK/macOS/
CFLAGS = -std=c++17 -I$(VULKAN_SDK_PATH)/include -DNDEBUG
LDFLAGS = -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan

VulkanTest: test.cpp
	g++ $(CFLAGS) -o VulkanTest test.cpp $(LDFLAGS)

VulkanApp: app.cpp
	g++ $(CFLAGS) -o VulkanApp app.cpp $(LDFLAGS)

.PHONY: test clean

test: VulkanTest
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/explicit_layer.d ./VulkanTest

app: VulkanApp
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/explicit_layer.d ./VulkanApp

clean:
	rm -f VulkanTest VulkanApp
